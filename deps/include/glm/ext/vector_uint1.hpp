/// @ref ext_vector_uint1
/// @file glm/ext/vector_uint1.hpp
///
/// @defgroup ext_vector_uint1 GLM_EXT_vector_uint1
/// @ingroup ext
///
/// Exposes uvec1 vector type.
///
/// Include <glm/ext/vector_uvec1.hpp> to use the features of this extension.
///
/// @see ext_vector_int1 extension.
/// @see ext_vector_uint1_precision extension.

#pragma once

#include "../detail/type_vec1.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_vector_uint1 extension included")
#endif

namespace glm
{
	/// @addtogroup ext_vector_uint1
	/// @{

	/// 1 component vector of uint32_teger numbers.
	typedef vec<1, uint32_t, defaultp>			uvec1;

	/// @}
}//namespace glm

