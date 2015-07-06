//
// Created by LE, Duc Anh on 7/3/15.
//

#ifndef CLOUD_E_PLUS_RELATION_RELATIONFETCHER_H
#define CLOUD_E_PLUS_RELATION_RELATIONFETCHER_H

namespace Cloude {
    namespace Relation {

        class RelationFetcher {

        public:
            RelationFetcher() = default;
            RelationFetcher(const RelationFetcher &) = default;
            RelationFetcher(RelationFetcher &&) = default;
            RelationFetcher &operator=(const RelationFetcher &) = default;
            RelationFetcher &operator=(RelationFetcher &&) = default;
            virtual ~RelationFetcher() = default;
        };
    }
}


#endif //CLOUD_E_PLUS_RELATION_RELATIONFETCHER_H
