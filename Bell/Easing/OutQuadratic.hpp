//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include "InQuadratic.hpp"

namespace Bell::Easing {

	/**
	 * @brief      ease out quad
	 */
	template <typename FloatType>
	struct OutQuadratic
	{
		static_assert(std::is_floating_point<FloatType>::value, "");
		using value_type = FloatType;

		constexpr FloatType operator()(FloatType t) const noexcept
		{
			return FloatType(1) - InQuadratic<FloatType>()(FloatType(1) - t);
		}
	};

}	//	namespace Bell::Easing
