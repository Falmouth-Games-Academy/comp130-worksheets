// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CFPS_cfpsCharacter_generated_h
#error "cfpsCharacter.generated.h already included, missing '#pragma once' in cfpsCharacter.h"
#endif
#define CFPS_cfpsCharacter_generated_h

#define cfps_Source_cfps_cfpsCharacter_h_11_RPC_WRAPPERS
#define cfps_Source_cfps_cfpsCharacter_h_11_RPC_WRAPPERS_NO_PURE_DECLS
#define cfps_Source_cfps_cfpsCharacter_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAcfpsCharacter(); \
	friend CFPS_API class UClass* Z_Construct_UClass_AcfpsCharacter(); \
	public: \
	DECLARE_CLASS(AcfpsCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/cfps"), NO_API) \
	DECLARE_SERIALIZER(AcfpsCharacter) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define cfps_Source_cfps_cfpsCharacter_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesAcfpsCharacter(); \
	friend CFPS_API class UClass* Z_Construct_UClass_AcfpsCharacter(); \
	public: \
	DECLARE_CLASS(AcfpsCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/cfps"), NO_API) \
	DECLARE_SERIALIZER(AcfpsCharacter) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define cfps_Source_cfps_cfpsCharacter_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AcfpsCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AcfpsCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AcfpsCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AcfpsCharacter); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AcfpsCharacter(const AcfpsCharacter& InCopy); \
public:


#define cfps_Source_cfps_cfpsCharacter_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AcfpsCharacter(const AcfpsCharacter& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AcfpsCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AcfpsCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AcfpsCharacter)


#define cfps_Source_cfps_cfpsCharacter_h_8_PROLOG
#define cfps_Source_cfps_cfpsCharacter_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	cfps_Source_cfps_cfpsCharacter_h_11_RPC_WRAPPERS \
	cfps_Source_cfps_cfpsCharacter_h_11_INCLASS \
	cfps_Source_cfps_cfpsCharacter_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define cfps_Source_cfps_cfpsCharacter_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	cfps_Source_cfps_cfpsCharacter_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	cfps_Source_cfps_cfpsCharacter_h_11_INCLASS_NO_PURE_DECLS \
	cfps_Source_cfps_cfpsCharacter_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID cfps_Source_cfps_cfpsCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
