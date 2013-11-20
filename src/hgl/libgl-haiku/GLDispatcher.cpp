/*
 * Copyright 1998-1999 Precision Insight, Inc., Cedar Park, Texas.
 * Copyright 2000-2012 Haiku, Inc. All Rights Reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		Brian Paul <brian.e.paul@gmail.com>
 *		Philippe Houdoin <philippe.houdoin@free.fr>
 *		Alexander von Gluck IV <kallisti5@unixzen.com>
 */


extern "C" {
#include "glapi/glapi.h"
#include "glapi/glapi_priv.h"

/*
 * NOTE: this file portion implements C-based dispatch of the OpenGL entrypoints
 * (glAccum, glBegin, etc).
 * This code IS NOT USED if we're compiling on an x86 system and using
 * the glapi_x86.S assembly code.
 */
#if !(defined(USE_X86_ASM) || defined(USE_SPARC_ASM))

#define KEYWORD1 PUBLIC
#define KEYWORD2
#define NAME(func) gl##func

#define DISPATCH(func, args, msg)					\
	const struct _glapi_table* dispatch;					\
	dispatch = _glapi_Dispatch ? _glapi_Dispatch : _glapi_get_dispatch();\
	(dispatch->func) args

#define RETURN_DISPATCH(func, args, msg) 				\
	const struct _glapi_table* dispatch;					\
	dispatch = _glapi_Dispatch ? _glapi_Dispatch : _glapi_get_dispatch();\
	return (dispatch->func) args

#endif
}


/* NOTE: this file portion implement a thin OpenGL entrypoints dispatching
	C++ wrapper class
 */

#include "GLDispatcher.h"

BGLDispatcher::BGLDispatcher()
{
}


BGLDispatcher::~BGLDispatcher()
{
}


status_t
BGLDispatcher::CheckTable(const struct _glapi_table* table)
{
	_glapi_check_table(table ? table : _glapi_get_dispatch());
	return B_OK;
}


status_t
BGLDispatcher::SetTable(struct _glapi_table* table)
{
	_glapi_set_dispatch(table);
	return B_OK;
}

// TODO: These were inlined, however gcc2 seems to have a bug
// where inlines that call extern "C" functions called from C++
// code result in the originating call using the C++ symbol linkage
// for a C function
void
BGLDispatcher::SetCurrentContext(void* context)
{
	_glapi_set_context(context);
}


void*
BGLDispatcher::CurrentContext()
{
	return _glapi_get_context();
}


struct _glapi_table*
BGLDispatcher::Table()
{
	return _glapi_get_dispatch();
}


uint32
BGLDispatcher::TableSize()
{
	return _glapi_get_dispatch_table_size();
}


const _glapi_proc
BGLDispatcher::operator[](const char* functionName)
{
	return _glapi_get_proc_address(functionName);
}


const char*
BGLDispatcher::operator[](uint32 offset)
{
	return _glapi_get_proc_name((GLuint) offset);
}


const _glapi_proc
BGLDispatcher::AddressOf(const char* functionName)
{
	return _glapi_get_proc_address(functionName);
}


uint32
BGLDispatcher::OffsetOf(const char* functionName)
{
	return (uint32) _glapi_get_proc_offset(functionName);
}
