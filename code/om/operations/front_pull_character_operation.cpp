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
#if defined( Om_Operations_FrontPullCharacterOperation_ )

	#include "om/operations/pull_operation.hpp"

// MARK: Om::Operations::FrontPullCharacterOperation

	#define Type_ Om::Operations::FrontPullCharacterOperation

// MARK: public (static)

inline char const * Type_::GetName()
{
	return( Om_Operations_FrontPullCharacterOperation_GetName_() );
}

template< typename TheEvaluandTaker>
inline void Type_::Give( TheEvaluandTaker & theEvaluandTaker )
{
	theEvaluandTaker.TakeEvaluand(
		std::auto_ptr< Evaluand >(
			new PullOperation< Operator, FrontPullCharacterOperation >
		)
	);
}

template< typename TheQueue >
inline void Type_::Pull( Operator & theOperator, TheQueue & theQueue )
{
	theOperator.FrontGiveSegment< boost::locale::boundary::character >(
		theQueue
	);
}

	#undef Type_

#else
	#include "om/operations/front_pull_character_operation.hpp"

	#if defined( Om_Macros_Test_ )

		#include "om/environment.hpp"
		#include "UnitTest++.h"

namespace Om
{
	namespace Operations
	{
		// MARK: -
		SUITE( FrontPullCharacterOperation )
		{
			TEST( General )
			{
				CHECK_EQUAL(
					"{1}{`{2`}three}",
					Environment().Evaluate( "<-characters {1{2}three}" )
				);

				CHECK_EQUAL(
					"{` }{}",
					Environment().Evaluate( "<-characters {` }" )
				);

				CHECK_EQUAL(
					"{" "\xC3\x98" "\xCC\x81" "}{a}",
					Environment().Evaluate( "<-characters {" "\xC7\xBE" "a}" )
				);

				CHECK_EQUAL(
					"{` }{}",
					Environment().Evaluate( "<-characters { }" )
				);

				CHECK_EQUAL(
					"{}{}",
					Environment().Evaluate( "<-characters {}" )
				);

				CHECK_EQUAL(
					"<-characters",
					Environment().Evaluate( "<-characters" )
				);
			}

			TEST( MultiCodePointCharacter )
			{
				CHECK_EQUAL(
					(
						"{"
							"\xE1\x84\x80" "\xE1\x85\xA1"
						"}{" "\xE1\x84\x82" "}"
					),
					Environment().Evaluate(
						"<-characters"
						"{" "\xE1\x84\x80" "\xE1\x85\xA1" "\xE1\x84\x82" "}"
					)
				);
			}
		}
	}
}

	#endif

#endif
