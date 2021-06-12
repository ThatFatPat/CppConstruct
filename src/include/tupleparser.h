#pragma once

#include "structparser.h"

template <typename... Parsers>
using TupleParser = StructParser<ParsingTypeTuple<Parsers...>, Parsers...>;
