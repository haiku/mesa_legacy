/*
 * Copyright 1998-1999 Precision Insight, Inc., Cedar Park, Texas.
 * Copyright 2000-2012 Haiku, Inc. All Rights Reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		Brian Paul <brian.e.paul@gmail.com>
 *		Philippe Houdoin <philippe.houdoin@free.fr>
 */
#ifndef GLDISPATCHER_H
#define GLDISPATCHER_H


#include <BeBuild.h>
#include <GL/gl.h>
#include <SupportDefs.h>

#include "glheader.h"

extern "C" {
#include "glapi/glapi.h"
}


class BGLDispatcher
{
		// Private unimplemented copy constructors
		BGLDispatcher(const BGLDispatcher &);
		BGLDispatcher & operator=(const BGLDispatcher &);

	public:
		BGLDispatcher();
		~BGLDispatcher();

		void 					SetCurrentContext(void* context);
		void*					CurrentContext();

		struct _glapi_table* 	Table();
		status_t				CheckTable(
									const struct _glapi_table* dispatch = NULL);
		status_t				SetTable(struct _glapi_table* dispatch);
		uint32					TableSize();

		const _glapi_proc 		operator[](const char* functionName);
		const char*				operator[](uint32 offset);

		const _glapi_proc		AddressOf(const char* functionName);
		uint32					OffsetOf(const char* functionName);
};


#endif	// GLDISPATCHER_H
