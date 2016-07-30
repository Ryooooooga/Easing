//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include "InBack.hpp"

namespace Bell::Easing {

	/**
	 * @brief      ease out back
	 */
	template <typename FloatType>
	class OutBack
	{
		static_assert(std::is_floating_point<FloatType>::value, "");

		InBack<FloatType> in_;

	public:
		using value_type = FloatType;

		constexpr OutBack(FloatType s = FloatType(1.70158)) noexcept
			: in_(s) {}

		constexpr FloatType operator()(FloatType t) const noexcept
		{
			return FloatType(1) - in_(FloatType(1) - t);
		}
	};

}	//	namespace Bell::Easing
