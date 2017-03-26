// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WORKSHEETC_Enemy_generated_h
#error "Enemy.generated.h already included, missing '#pragma once' in Enemy.h"
#endif
#define WORKSHEETC_Enemy_generated_h

#define WorksheetC_Source_WorksheetC_Enemy_h_11_RPC_WRAPPERS
#define WorksheetC_Source_WorksheetC_Enemy_h_11_RPC_WRAPPERS_NO_PURE_DECLS
#define WorksheetC_Source_WorksheetC_Enemy_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAEnemy(); \
	friend WORKSHEETC_API class UClass* Z_Construct_UClass_AEnemy(); \
	public: \
	DECLARE_CLASS(AEnemy, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/WorksheetC"), NO_API) \
	DECLARE_SERIALIZER(AEnemy) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define WorksheetC_Source_WorksheetC_Enemy_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesAEnemy(); \
	friend WORKSHEETC_API class UClass* Z_Construct_UClass_AEnemy(); \
	public: \
	DECLARE_CLASS(AEnemy, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/WorksheetC"), NO_API) \
	DECLARE_SERIALIZER(AEnemy) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define WorksheetC_Source_WorksheetC_Enemy_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemy(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEnemy) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemy); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemy(AEnemy&&); \
	NO_API AEnemy(const AEnemy&); \
public:


#define WorksheetC_Source_WorksheetC_Enemy_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemy(AEnemy&&); \
	NO_API AEnemy(const AEnemy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemy)


#define WorksheetC_Source_WorksheetC_Enemy_h_11_PRIVATE_PROPERTY_OFFSET
#define WorksheetC_Source_WorksheetC_Enemy_h_8_PROLOG
#define WorksheetC_Source_WorksheetC_Enemy_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WorksheetC_Source_WorksheetC_Enemy_h_11_PRIVATE_PROPERTY_OFFSET \
	WorksheetC_Source_WorksheetC_Enemy_h_11_RPC_WRAPPERS \
	WorksheetC_Source_WorksheetC_Enemy_h_11_INCLASS \
	WorksheetC_Source_WorksheetC_Enemy_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define WorksheetC_Source_WorksheetC_Enemy_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WorksheetC_Source_WorksheetC_Enemy_h_11_PRIVATE_PROPERTY_OFFSET \
	WorksheetC_Source_WorksheetC_Enemy_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	WorksheetC_Source_WorksheetC_Enemy_h_11_INCLASS_NO_PURE_DECLS \
	WorksheetC_Source_WorksheetC_Enemy_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID WorksheetC_Source_WorksheetC_Enemy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
