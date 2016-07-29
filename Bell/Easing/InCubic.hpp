//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include <type_traits>

namespace Bell::Easing {

	/**
	 * @brief      ease in cubic
	 */
	template <typename FloatType>
	struct InCubic
	{
		static_assert(std::is_floating_point<FloatType>::value, "");
		using value_type = FloatType;

		constexpr FloatType operator()(FloatType t) const noexcept
		{
			return
				t < FloatType(0) ? FloatType(0) :
				t > FloatType(1) ? FloatType(1) : t*t*t;
		}
	};

}	//	namespace Bell::Easing
