#pragma once

#if !defined __WINE__
#   include <QCoreApplication>
#   define otr_tr(str, ...) (QCoreApplication::translate(OTR_MODULE_NAME, (str), __VA_ARGS__))
#   define _(x, ...) otr_tr((x), __VA_ARGS__)
#endif

#if defined _MSC_VER
#
#   define MEMORY_BARRIER _ReadWriteBarrier()
#else
#   define MEMORY_BARRIER asm volatile("" ::: "memory")
#endif

#if defined _MSC_VER
#   define never_inline __declspec(noinline)
#elif defined __GNUG__
#   define never_inline __attribute__((noinline))
#else
#   define never_inline
#endif

#if defined __GNUG__
#   define restrict_ptr __restrict
#elif defined _MSC_VER
#   define restrict_ptr __restrict
#else
#   define restrict_ptr
#endif

#if defined _MSC_VER
#   define restrict_ref restrict_ptr
#elif defined __GNUG__
#   define restrict_ref restrict_ptr
#else
#   define restrict_ref
#endif

#if defined _MSC_VER
#   define force_inline __forceinline
#elif defined __GNUG__
#   define force_inline __attribute__((always_inline, gnu_inline)) inline
#else
#   define force_inline inline
#endif

#ifdef Q_CREATOR_RUN
#   define warn_result_unused
#elif defined _MSC_VER
#   define warn_result_unused _Check_return_
#else
#   define warn_result_unused __attribute__((warn_unused_result))
#endif

#if defined __GNUG__
#   define unused(t, i) t __attribute__((unused)) i
#else
#   define unused(t, i) t
#endif

#if defined _MSC_VER
#   define aligned_struct(x) struct __declspec(align(x))
#else
#   define aligned_struct(x) struct __attribute__((__aligned__(x)))
#endif

#if defined __GNUC__
#   define likely(x)       __builtin_expect(!!(x),1)
#   define unlikely(x)     __builtin_expect(!!(x),0)
#else
#   define likely(x) (x)
#   define unlikely(x) (x)
#endif
