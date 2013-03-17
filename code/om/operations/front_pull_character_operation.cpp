/*!
\file
	\brief
		<a href="http://om-language.org">Om</a> source file.
	\version
		0.1.2
	\date
		2012-2013
	\copyright
		Copyright (c) <a href="http://sparist.com">Sparist</a>. All rights reserved. This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.
*/

#ifndef Om_Operations_FrontPullCharacterOperation_

	#include "om/operations/front_pull_character_operation.hpp"

	#ifdef Om_Macros_Test_

		#ifndef Om_Macros_Precompilation_

			#include "boost/test/unit_test.hpp"

		#endif

namespace Om {

	namespace Operations {

		BOOST_AUTO_TEST_SUITE(FrontPullCharacterOperationTest)

			BOOST_AUTO_TEST_CASE(DefinitionTest) {
				BOOST_CHECK_EQUAL(
					"{<-characters}",
					System::Get().Evaluate("drop find {<-characters} system")
				);
			}

			BOOST_AUTO_TEST_CASE(GeneralTest) {
				BOOST_CHECK_EQUAL(
					"{1}{`{2`}three}",
					System::Get().Evaluate("<-characters {1{2}three}")
				);

				BOOST_CHECK_EQUAL(
					"{` }{}",
					System::Get().Evaluate("<-characters {` }")
				);

				BOOST_CHECK_EQUAL(
					(
						"{"
						"\xC3\x98"
						"\xCC\x81"
						"}{a}"
					),
					System::Get().Evaluate(
						"<-characters {"
						"\xC7\xBE"
						"a}"
					)
				);

				BOOST_CHECK_EQUAL(
					"{` }{}",
					System::Get().Evaluate("<-characters { }")
				);

				BOOST_CHECK_EQUAL(
					"{}{}",
					System::Get().Evaluate("<-characters {}")
				);

				BOOST_CHECK_EQUAL(
					"<-characters",
					System::Get().Evaluate("<-characters")
				);
			}

			BOOST_AUTO_TEST_CASE(MultiCodePointCharacterTest) {
				BOOST_CHECK_EQUAL(
					(
						"{"
						"\xE1\x84\x80"
						"\xE1\x85\xA1"
						"}{"
						"\xE1\x84\x82"
						"}"
					),
					System::Get().Evaluate(
						"<-characters"
						"{"
						"\xE1\x84\x80"
						"\xE1\x85\xA1"
						"\xE1\x84\x82"
						"}"
					)
				);
			}

		BOOST_AUTO_TEST_SUITE_END()

	}

}

	#endif

#else

	#include "om/operations/pull_operation.hpp"

// MARK: - Om::Operations::FrontPullCharacterOperation

	#define Type_ \
	Om::Operations::FrontPullCharacterOperation

// MARK: public (static)

inline char const * Type_::GetName() {
	return Om_Operations_FrontPullCharacterOperation_GetName_();
}

inline void Type_::Give(Evaluation & theEvaluation) {
	theEvaluation.TakeOperation(
		std::auto_ptr<Operation>(
			new PullOperation<
				Operator,
				FrontPullCharacterOperation
			>
		)
	);
}

template <typename TheConsumer>
inline void Type_::Pull(
	Operator & theOperator,
	TheConsumer & theConsumer
) {
	theOperator.FrontGiveSegment<boost::locale::boundary::character>(theConsumer);
}

	#undef Type_

#endif
