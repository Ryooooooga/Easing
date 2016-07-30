//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include <type_traits>

namespace Bell::Math {

	template <typename FloatType>
	constexpr std::enable_if_t<std::is_floating_point<FloatType>::value, FloatType> pi = FloatType(3.1415926535897932384626433832795L);

}	//	namespace Bell::Math
