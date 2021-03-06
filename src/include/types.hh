#ifndef TYPES_HH
#define TYPES_HH

#include "common.hh"

enum class DataType
{
	NIL,
    INT,
	INTARR,
    STR,
	STRARR,
    BLK,
	BLKARR,
};

struct ExprType
{
	DataType type;
	struct
	{
		i64 int_val;
		char *str_val;
	} as;
};

inline DataType convert_to_arr_type(DataType type)
{
	return static_cast<DataType>(static_cast<int>(type) + 1);
}

inline DataType convert_from_arr_type(DataType type)
{
	return static_cast<DataType>(static_cast<int>(type) - 1);
}

inline bool is_arr_type(DataType type)
{
	return type == DataType::INTARR || type == DataType::STRARR || type == DataType::BLKARR;
}

#endif /* TYPES_HH */