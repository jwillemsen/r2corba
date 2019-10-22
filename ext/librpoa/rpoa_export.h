// -*- C++ -*-
/*--------------------------------------------------------------------
#
# Author: Martin Corino
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the R2CORBA LICENSE which is
# included with this program.
#
# Copyright (c) Remedy IT Expertise BV
#-------------------------------------------------------------------*/
#ifndef R2TAO_POA_EXPORT_H
#define R2TAO_POA_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (R2TAO_POA_HAS_DLL)
#  define R2TAO_POA_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && R2TAO_POA_HAS_DLL */

#if !defined (R2TAO_POA_HAS_DLL)
#  define R2TAO_POA_HAS_DLL 1
#endif /* ! R2TAO_POA_HAS_DLL */

#if defined (R2TAO_POA_HAS_DLL) && (R2TAO_POA_HAS_DLL == 1)
#  if defined (R2TAO_POA_BUILD_DLL)
#    define R2TAO_POA_EXPORT ACE_Proper_Export_Flag
#    define R2TAO_POA_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define R2TAO_POA_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* R2TAO_POA_BUILD_DLL */
#    define R2TAO_POA_EXPORT ACE_Proper_Import_Flag
#    define R2TAO_POA_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define R2TAO_POA_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* R2TAO_POA_BUILD_DLL */
#else /* R2TAO_POA_HAS_DLL == 1 */
#  define R2TAO_POA_EXPORT
#  define R2TAO_POA_SINGLETON_DECLARATION(T)
#  define R2TAO_POA_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* R2TAO_POA_HAS_DLL == 1 */

#endif /* R2TAO_POA_EXPORT_H */

// End of auto generated file.
