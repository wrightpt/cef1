// Copyright (c) 2016 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//

#ifndef CEF_INCLUDE_CAPI_CEF_DRAG_HANDLER_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_DRAG_HANDLER_CAPI_H_
#pragma once

#include "include/capi/cef_base_capi.h"
#include "include/capi/cef_browser_capi.h"
#include "include/capi/cef_drag_data_capi.h"

#ifdef __cplusplus
extern "C" {
#endif


///
// Implement this structure to handle events related to dragging. The functions
// of this structure will be called on the UI thread.
///
typedef struct _cef_drag_handler_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Called when an external drag event enters the browser window. |dragData|
  // contains the drag event data and |mask| represents the type of drag
  // operation. Return false (0) for default drag handling behavior or true (1)
  // to cancel the drag event.
  ///
  int (CEF_CALLBACK *on_drag_enter)(struct _cef_drag_handler_t* self,
      struct _cef_browser_t* browser, struct _cef_drag_data_t* dragData,
      cef_drag_operations_mask_t mask);

  ///
  // Called whenever draggable regions for the browser window change. These can
  // be specified using the '-webkit-app-region: drag/no-drag' CSS-property. If
  // draggable regions are never defined in a document this function will also
  // never be called. If the last draggable region is removed from a document
  // this function will be called with an NULL vector.
  ///
  void (CEF_CALLBACK *on_draggable_regions_changed)(
      struct _cef_drag_handler_t* self, struct _cef_browser_t* browser,
      size_t regionsCount, cef_draggable_region_t const* regions);
} cef_drag_handler_t;


#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_DRAG_HANDLER_CAPI_H_
