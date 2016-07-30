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

	/**
	 * @brief      NaNか判別する
	 *
	 * @param[in]  x          NaNかどうか調べる浮動小数点数
	 *
	 * @tparam     FloatType  浮動小数点数型
	 *
	 * @return     xがNaNなら true NaNでないなら false
	 */
	template <typename FloatType>
	constexpr bool isNaN(FloatType x) noexcept
	{
		static_assert(std::is_floating_point<FloatType>::value, "");
		return x != x;
	}

}	//	namespace Bell::Math
