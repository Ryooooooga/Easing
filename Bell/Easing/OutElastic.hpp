//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include "InElastic.hpp"

namespace Bell::Easing {

	/**
	 * @brief      ease out elastic
	 */
	template <typename FloatType>
	class OutElastic
	{
		static_assert(std::is_floating_point<FloatType>::value, "");

		InElastic<FloatType> in_;

	public:
		using value_type = FloatType;

		OutElastic(FloatType a = FloatType(1.0), FloatType p = FloatType(0.3)) noexcept
			: in_(a, p) {}

		FloatType operator()(FloatType t) const noexcept
		{
			return FloatType(1) - in_(FloatType(1) - t);
		}
	};

}	//	namespace Bell::Easing
