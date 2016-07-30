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
	 * @brief      ease out bounce
	 */
	template <typename FloatType>
	class OutBounce
	{
		static_assert(std::is_floating_point<FloatType>::value, "");

	public:
		using value_type = FloatType;

		constexpr FloatType operator()(FloatType t) const noexcept
		{
			return
				t < FloatType(0.0/2.75) ? FloatType(0) :
				t < FloatType(1.0/2.75) ? FloatType(7.5625)*(t-0.00/2.75)*(t-0.00/2.75) :
				t < FloatType(2.0/2.75) ? FloatType(7.5625)*(t-1.50/2.75)*(t-1.50/2.75) + FloatType(0.75) :
				t < FloatType(2.5/2.75) ? FloatType(7.5625)*(t-2.25/2.75)*(t-2.25/2.75) + FloatType(0.9375) :
				t > FloatType(1) ? 1 : FloatType(7.5625)*(t-2.625/2.75)*(t-2.625/2.75) + FloatType(0.984375);
		}
	};

}	//	namespace Bell::Easing
