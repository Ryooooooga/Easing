//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include <cmath>
#include <algorithm>
#include "../Math/Constants.hpp"

namespace Bell::Easing {

	/**
	 * @brief      ease in elastic
	 */
	template <typename FloatType>
	class InElastic
	{
		static_assert(std::is_floating_point<FloatType>::value, "");

		FloatType a_, p_, s_;
		
	public:
		using value_type = FloatType;

		InElastic(FloatType a = FloatType(1.0), FloatType p = FloatType(0.3)) noexcept
			: a_((std::max)(a, FloatType(1.0))), p_(p), s_(p_ / Math::pi<FloatType> / 2 * std::asin(1 / a_)) {}

		FloatType operator()(FloatType t) const noexcept
		{
			return
				t <= FloatType(0) ? FloatType(0) :
				t >= FloatType(1) ? FloatType(1) : -a_ * std::exp2(10*(t - 1)) * std::sin((t - 1 - s_) * 2*Math::pi<FloatType> / p_);
		}
	};

}	//	namespace Bell::Easing
