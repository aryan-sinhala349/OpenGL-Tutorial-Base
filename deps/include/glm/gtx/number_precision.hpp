/// @ref gtx_number_precision
/// @file glm/gtx/number_precision.hpp
///
/// @see core (dependence)
/// @see gtc_type_precision (dependence)
/// @see gtc_quaternion (dependence)
///
/// @defgroup gtx_number_precision GLM_GTX_number_precision
/// @ingroup gtx
///
/// Include <glm/gtx/number_precision.hpp> to use the features of this extension.
///
/// Defined size types.

#pragma once

// Dependency:
#include "../glm.hpp"
#include "../gtc/type_precision.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	ifndef GLM_ENABLE_EXPERIMENTAL
#		pragma message("GLM: GLM_GTX_number_precision is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#	else
#		pragma message("GLM: GLM_GTX_number_precision extension included")
#	endif
#endif

namespace glm{
namespace gtx
{
	/////////////////////////////
	// uint32_t vector types

	/// @addtogroup gtx_number_precision
	/// @{

	typedef u8			u8vec1;		//!< \brief 8bit uint32_teger scalar. (from GLM_GTX_number_precision extension)
	typedef u16			u16vec1;    //!< \brief 16bit uint32_teger scalar. (from GLM_GTX_number_precision extension)
	typedef u32			u32vec1;    //!< \brief 32bit uint32_teger scalar. (from GLM_GTX_number_precision extension)
	typedef u64			u64vec1;    //!< \brief 64bit uint32_teger scalar. (from GLM_GTX_number_precision extension)

	//////////////////////
	// Float vector types

	typedef f32			f32vec1;    //!< \brief Single-qualifier floating-point scalar. (from GLM_GTX_number_precision extension)
	typedef f64			f64vec1;    //!< \brief Single-qualifier floating-point scalar. (from GLM_GTX_number_precision extension)

	//////////////////////
	// Float matrix types

	typedef f32			f32mat1;	//!< \brief Single-qualifier floating-point scalar. (from GLM_GTX_number_precision extension)
	typedef f32			f32mat1x1;	//!< \brief Single-qualifier floating-point scalar. (from GLM_GTX_number_precision extension)
	typedef f64			f64mat1;	//!< \brief Double-qualifier floating-point scalar. (from GLM_GTX_number_precision extension)
	typedef f64			f64mat1x1;	//!< \brief Double-qualifier floating-point scalar. (from GLM_GTX_number_precision extension)

	/// @}
}//namespace gtx
}//namespace glm

#include "number_precision.inl"
