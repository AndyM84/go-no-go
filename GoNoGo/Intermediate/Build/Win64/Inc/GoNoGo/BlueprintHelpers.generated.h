// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef GONOGO_BlueprintHelpers_generated_h
#error "BlueprintHelpers.generated.h already included, missing '#pragma once' in BlueprintHelpers.h"
#endif
#define GONOGO_BlueprintHelpers_generated_h

#define UBlueprintHelpers_EVENTPARMS
#define UBlueprintHelpers_RPC_WRAPPERS
#define UBlueprintHelpers_RPC_WRAPPERS_NO_PURE_DECLS \
	static inline void StaticChecks_Implementation_Validate() \
	{ \
	}


#define UBlueprintHelpers_CALLBACK_WRAPPERS
#define UBlueprintHelpers_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUBlueprintHelpers(); \
	friend GONOGO_API class UClass* Z_Construct_UClass_UBlueprintHelpers(); \
	public: \
	DECLARE_CLASS(UBlueprintHelpers, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, GoNoGo, NO_API) \
	DECLARE_SERIALIZER(UBlueprintHelpers) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<UBlueprintHelpers*>(this); }


#define UBlueprintHelpers_INCLASS \
	private: \
	static void StaticRegisterNativesUBlueprintHelpers(); \
	friend GONOGO_API class UClass* Z_Construct_UClass_UBlueprintHelpers(); \
	public: \
	DECLARE_CLASS(UBlueprintHelpers, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, GoNoGo, NO_API) \
	DECLARE_SERIALIZER(UBlueprintHelpers) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<UBlueprintHelpers*>(this); }


#define UBlueprintHelpers_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UBlueprintHelpers(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBlueprintHelpers) \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UBlueprintHelpers(const UBlueprintHelpers& InCopy); \
public:


#define UBlueprintHelpers_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UBlueprintHelpers(const class FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UBlueprintHelpers(const UBlueprintHelpers& InCopy); \
public: \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBlueprintHelpers)


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME UBlueprintHelpers


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
UBlueprintHelpers_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UBlueprintHelpers_RPC_WRAPPERS \
	UBlueprintHelpers_CALLBACK_WRAPPERS \
	UBlueprintHelpers_INCLASS \
	UBlueprintHelpers_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_POP


#define GENERATED_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UBlueprintHelpers_RPC_WRAPPERS_NO_PURE_DECLS \
	UBlueprintHelpers_CALLBACK_WRAPPERS \
	UBlueprintHelpers_INCLASS_NO_PURE_DECLS \
	UBlueprintHelpers_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_POP


