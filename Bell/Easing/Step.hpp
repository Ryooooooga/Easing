//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include <cassert>
#include <type_traits>

namespace Bell::Easing {

	/**
	 * @brief      ease step
	 */
	template <typename FloatType>
	class Step
	{
		static_assert(std::is_floating_point<FloatType>::value, "");

		FloatType a_;

	public:
		using value_type = FloatType;

		constexpr Step(FloatType a) noexcept
			: a_((assert(0 <= a && a <= 1), a)) {}

		constexpr FloatType operator()(FloatType t) const noexcept
		{
			return t < a_ ? FloatType(0) : FloatType(1);
		}
	};

}	//	namespace Bell::Easing
