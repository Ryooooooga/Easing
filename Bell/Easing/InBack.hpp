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
	 * @brief      ease in back
	 */
	template <typename FloatType>
	class InBack
	{
		static_assert(std::is_floating_point<FloatType>::value, "");

		FloatType s_;
		
	public:
		using value_type = FloatType;

		constexpr InBack(FloatType s = FloatType(1.70158)) noexcept
			: s_(s) {}

		constexpr FloatType operator()(FloatType t) const noexcept
		{
			return
				t < FloatType(0) ? FloatType(0) :
				t > FloatType(1) ? FloatType(1) : t * t * ((s_ + 1) * t - s_);
		}
	};

}	//	namespace Bell::Easing
