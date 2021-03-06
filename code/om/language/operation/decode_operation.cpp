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

#ifndef Om_Language_Operation_DecodeOperation_

	#include "om/language/operation/decode_operation.hpp"

	#ifdef Om_Macro_Test_

		#include "om/language/system.hpp"

		#ifndef Om_Macro_Precompilation_

			#include "boost/test/unit_test.hpp"

		#endif

namespace Om {

	namespace Language {

		namespace Operation {

			BOOST_AUTO_TEST_SUITE(DecodeOperationTest)

				BOOST_AUTO_TEST_CASE(DefinitionTest) {
					BOOST_CHECK_EQUAL(
						"{decode}",
						System::Get().Evaluate("drop find {decode} system")
					);
				}

				BOOST_AUTO_TEST_CASE(SimpleTest) {
					BOOST_CHECK_EQUAL(
						"{`{`}` {{}} {quote{s}} }",
						System::Get().Evaluate("decode {```{```}``` `{`{`}`}` {quote{s}} }")
					);

					BOOST_CHECK_EQUAL(
						"{{} {{}} {quote{s}} }",
						System::Get().Evaluate("decode {`{`}` {{}} {quote{s}} }")
					);

					BOOST_CHECK_EQUAL(
						"{ the {end: `} really: } ! }",
						System::Get().Evaluate("decode {` the` `{end:` ```}` really:` `}` !` }")
					);

					// Test that each remaining encoded Operand Symbol is decoded.
					BOOST_CHECK_EQUAL(
						"{ the {end: } really: }",
						System::Get().Evaluate("decode { the {end: `} really: } ! }")
					);

					BOOST_CHECK_EQUAL(
						"{ the {end: } really: }",
						System::Get().Evaluate("decode { the {end: } really: }")
					);
				}

			BOOST_AUTO_TEST_SUITE_END()

		}

	}

}

	#endif

#else

	#include "om/language/literal.hpp"

// MARK: - Om::Language::Operation::DecodeOperation

	#define Type_ \
	Om::Language::Operation::DecodeOperation

// MARK: public (static)

inline char const * Type_::GetName() {
	return Om_Language_Operation_DecodeOperation_GetName_();
}

template <typename TheDecodeOperation>
inline void Type_::GiveElements(
	TheDecodeOperation &,
	Consumer & theConsumer
) {
	theConsumer.TakeElement(
		GetOperator()
	);
}

// MARK: public (non-static)

template <typename TheOperand>
inline bool Type_::TakeOperand(
	Evaluation & theEvaluation,
	TheOperand & theOperand
) {
	assert(
		!theOperand.IsEmpty()
	);
	return this->TakeQuotedProducer(
		theEvaluation,
		*theOperand.GetProgram()
	);
}

template <typename TheProducer>
inline bool Type_::TakeQuotedProducer(
	Evaluation & theEvaluation,
	TheProducer & theProducer
) {
	Literal theLiteral;
	{
		Operator theOperator;
		theOperator.TakeElements(theProducer);
		theOperator.Decode(theLiteral);
	}
	theEvaluation.TakeQuotedProducer(theLiteral);
	return true;
}

	#undef Type_

#endif
