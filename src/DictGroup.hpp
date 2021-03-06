/*
 * Open Chinese Convert
 *
 * Copyright 2010-2013 BYVoid <byvoid@byvoid.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Common.hpp"
#include "Dict.hpp"

namespace Opencc {
  class OPENCC_EXPORT DictGroup : public Dict {
  public:
    DictGroup();
    virtual ~DictGroup();
    virtual size_t KeyMaxLength() const;
    virtual Optional<DictEntryPtr> Match(const char* word);
    virtual Optional<DictEntryPtr> MatchPrefix(const char* word);
    virtual DictEntryPtrVectorPtr MatchAllPrefixes(const char* word);
    virtual DictEntryPtrVectorPtr GetLexicon();
    virtual void LoadFromDict(Dict* dictionary);
    void AddDict(DictPtr dict);
  private:
    size_t keyMaxLength;
    std::list<DictPtr> dicts;
  };
}
