// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FPS_cprojectile_generated_h
#error "cprojectile.generated.h already included, missing '#pragma once' in cprojectile.h"
#endif
#define FPS_cprojectile_generated_h

#define FPS_Source_FPS_cprojectile_h_11_RPC_WRAPPERS
#define FPS_Source_FPS_cprojectile_h_11_RPC_WRAPPERS_NO_PURE_DECLS
#define FPS_Source_FPS_cprojectile_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAcprojectile(); \
	friend FPS_API class UClass* Z_Construct_UClass_Acprojectile(); \
	public: \
	DECLARE_CLASS(Acprojectile, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/FPS"), NO_API) \
	DECLARE_SERIALIZER(Acprojectile) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define FPS_Source_FPS_cprojectile_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesAcprojectile(); \
	friend FPS_API class UClass* Z_Construct_UClass_Acprojectile(); \
	public: \
	DECLARE_CLASS(Acprojectile, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/FPS"), NO_API) \
	DECLARE_SERIALIZER(Acprojectile) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define FPS_Source_FPS_cprojectile_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API Acprojectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(Acprojectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, Acprojectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(Acprojectile); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API Acprojectile(const Acprojectile& InCopy); \
public:


#define FPS_Source_FPS_cprojectile_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API Acprojectile(const Acprojectile& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, Acprojectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(Acprojectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(Acprojectile)


#define FPS_Source_FPS_cprojectile_h_8_PROLOG
#define FPS_Source_FPS_cprojectile_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPS_Source_FPS_cprojectile_h_11_RPC_WRAPPERS \
	FPS_Source_FPS_cprojectile_h_11_INCLASS \
	FPS_Source_FPS_cprojectile_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FPS_Source_FPS_cprojectile_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPS_Source_FPS_cprojectile_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FPS_Source_FPS_cprojectile_h_11_INCLASS_NO_PURE_DECLS \
	FPS_Source_FPS_cprojectile_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FPS_Source_FPS_cprojectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
