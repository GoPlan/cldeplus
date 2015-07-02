//
// Created by LE, Duc Anh on 6/16/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_ENTITYRELATIONSHIP_H
#define CLOUD_E_PLUS_FOUNDATION_ENTITYRELATIONSHIP_H

namespace Cloude {
    namespace Foundation {
        class EntityRelationship {
        public:
            EntityRelationship() = default;
            EntityRelationship(const EntityRelationship &) = default;
            EntityRelationship(EntityRelationship &&) = default;
            EntityRelationship &operator=(const EntityRelationship &) = default;
            EntityRelationship &operator=(EntityRelationship &&) = default;
            virtual ~EntityRelationship() = default;
        };
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_ENTITYRELATIONSHIP_H
