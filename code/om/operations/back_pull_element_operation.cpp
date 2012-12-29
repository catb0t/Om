/*!
\file
	\brief
		Om cpp file.
	\version
		0.1
	\date
		2012
	\copyright
		Copyright (c) Jason Erb.
		All rights reserved.  This program and the accompanying materials are
		made available under the terms of the
		<a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse
		Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.
*/
#if defined( Om_Operations_BackPullElementOperation_ )

	#include "om/literal.hpp"
	#include "om/operations/pull_operation.hpp"

// MARK: Om::Operations::BackPullElementOperation

	#define Type_ Om::Operations::BackPullElementOperation

// MARK: public (static)

inline char const * Type_::GetName()
{
	return( Om_Operations_BackPullElementOperation_GetName_() );
}

inline void Type_::Give( Evaluation & theEvaluation )
{
	theEvaluation.TakeOperation(
		std::auto_ptr< Operation >(
			new PullOperation< Literal, BackPullElementOperation >
		)
	);
}

template< typename TheQueue >
inline void Type_::Pull( Literal & theLiteral, TheQueue & theQueue )
{
	theLiteral.BackGiveElement( theQueue );
}

	#undef Type_

#else
	#include "om/operations/back_pull_element_operation.hpp"

	#if defined( Om_Macros_Test_ )

		#include "om/system.hpp"
		#include "UnitTest++.h"

namespace Om
{
	namespace Operations
	{
		// MARK: -
		SUITE( BackPullElementOperation )
		{
			TEST( General )
			{
				CHECK_EQUAL(
					"{3}{1{2}}",
					System::Get().Evaluate( "element-> {1{2}3}" )
				);

				CHECK_EQUAL(
					"{2}{1 }",
					System::Get().Evaluate( "element-> {1 2}" )
				);

				CHECK_EQUAL(
					"{}{}",
					System::Get().Evaluate( "element-> {}" )
				);

				CHECK_EQUAL(
					"{only}{}",
					System::Get().Evaluate( "element-> {only}" )
				);

				CHECK_EQUAL(
					"element->",
					System::Get().Evaluate( "element->" )
				);
			}
		}
	}
}

	#endif

#endif