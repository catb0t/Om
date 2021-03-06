/*!
\file
	\brief
		<a href="http://github.com/sparist/Om">Om</a> source file.
	\version
		0.1.3
	\date
		2012-2014
	\copyright
		Copyright (c) <a href="http://sparist.com">Sparist</a>. All rights reserved. This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\author
		Jason Erb
*/

#ifndef Om_Language_Operation_LexiconBackPushOperation_

	#include "om/language/operation/lexicon_back_push_operation.hpp"

	#ifdef Om_Macro_Test_

		#ifndef Om_Macro_Precompilation_

			#include "boost/test/unit_test.hpp"

		#endif

namespace Om {

	namespace Language {

		namespace Operation {

			BOOST_AUTO_TEST_SUITE(LexiconBackPushOperationTest)

				BOOST_AUTO_TEST_CASE(DefinitionTest) {
					BOOST_CHECK_EQUAL(
						"{[lexicon]<-}",
						System::Get().Evaluate("drop find {[lexicon]<-} system")
					);
				}

			BOOST_AUTO_TEST_SUITE_END()

		}

	}

}

	#endif

#else

	#include "om/language/operation/lexicon_front_push_operation.hpp"
	#include "om/language/operation/swap_operation.hpp"

// MARK: - Om::Language::Operation::LexiconBackPushOperation

	#define Type_ \
	Om::Language::Operation::LexiconBackPushOperation

// MARK: public (static)

inline char const * Type_::GetName() {
	return Om_Language_Operation_LexiconBackPushOperation_GetName_();
}

inline void Type_::Give(Evaluation & theEvaluation) {
	LexiconFrontPushOperation::Give(theEvaluation);
	SwapOperation::Give(theEvaluation);
}

	#undef Type_

#endif
