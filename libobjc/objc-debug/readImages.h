//
//  readImages.h
//  objc
//
//  Created by Cooci on 2019/11/25.
//

#ifndef readImages_h
#define readImages_h
void _read_images {
    
    // 第一次进来 - 开始创建表 
    // gdb_objc_realized_classes : 所有类的表 - 包括实现的和没有实现的
    // allocatedClasses: 包含用objc_allocateClassPair分配的所有类（和元类）的表。(已分配)
    
    if (!doneOnce) {
           doneOnce = YES;
        // namedClasses
        // Preoptimized classes don't go in this table.
        // 4/3 is NXMapTable's load factor
        int namedClassesSize =
            (isPreoptimized() ? unoptimizedTotalClasses : totalClasses) * 4 / 3;
        gdb_objc_realized_classes =
            NXCreateMapTable(NXStrValueMapPrototype, namedClassesSize);
        
        allocatedClasses = NXCreateHashTable(NXPtrPrototype, 0, nil);
    }
    
    // 读取所有类的列表
    for (EACH_HEADER) {
        classref_t *classlist = _getObjc2ClassList(hi, &count);
    }
    
    // 获取所有的类引用
    for (EACH_HEADER) {
        Class *classrefs = _getObjc2ClassRefs(hi, &count);
    }

    // sel - 方法编号
    for (EACH_HEADER) {
        SEL *sels = _getObjc2SelectorRefs(hi, &count);
    }
    
    // 修复旧的objc_msgSend_fixup调用导致一些消息没有处理
    for (EACH_HEADER) {
        message_ref_t *refs = _getObjc2MessageRefs(hi, &count);
    }
    
    // 协议
    for (EACH_HEADER) {
        protocol_t **protolist = _getObjc2ProtocolList(hi, &count);
        for (i = 0; i < count; i++) {
            readProtocol(protolist[i], cls, protocol_map, isPreoptimized, isBundle);
        }
    }
    
    // 修复协议重映射
    // 获取所有的协议引用
    for (EACH_HEADER) {
       protocol_t **protolist = _getObjc2ProtocolRefs(hi, &count);
       for (i = 0; i < count; i++) {
           remapProtocolRef(&protolist[i]);
       }
    }
    
    // 实现非惰性类（用于+ load方法和静态实例）
     for (EACH_HEADER) {
         classref_t *classlist = _getObjc2NonlazyClassList(hi, &count);
     }
    
    // 在CF基础上，实现未来类
    if (resolvedFutureClasses) {
        for (i = 0; i < resolvedFutureClassCount; i++) {
            Class cls = resolvedFutureClasses[i];
            if (cls->isSwiftStable()) {
                _objc_fatal("Swift class is not allowed to be future");
            }
            realizeClassWithoutSwift(cls);
            cls->setInstancesRequireRawIsa(false/*inherited*/);
        }
        free(resolvedFutureClasses);
    }
    
    
    // 分类
    for (EACH_HEADER) {
        category_t **catlist = _getObjc2CategoryList(hi, &count);
    }
    
}



#endif /* readImages_h */
