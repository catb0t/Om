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

#ifndef Om_Language_Operation_PairOperation_

	#include "om/language/operation/pair_operation.hpp"

	#ifdef Om_Macro_Test_

		#ifndef Om_Macro_Precompilation_

			#include "boost/test/unit_test.hpp"

		#endif

namespace Om {

	namespace Language {

		namespace Operation {

			BOOST_AUTO_TEST_SUITE(PairOperationTest)

				BOOST_AUTO_TEST_CASE(DefinitionTest) {
					BOOST_CHECK_EQUAL(
						"{pair}",
						System::Get().Evaluate("drop find {pair} system")
					);
				}

				BOOST_AUTO_TEST_CASE(GeneralTest) {
					BOOST_CHECK_EQUAL(
						(
							"{1{2}\n"
							"3{4{5}6}}"
						),
						System::Get().Evaluate("pair {1{2}3}{4{5}6}")
					);

					BOOST_CHECK_EQUAL(
						"{1{2}{{5}6}}",
						System::Get().Evaluate("pair {1{2}}{{5}6}")
					);

					BOOST_CHECK_EQUAL(
						"{{{5}6}}",
						System::Get().Evaluate("pair {}{{5}6}")
					);

					BOOST_CHECK_EQUAL(
						(
							"{{5}\n"
							"6{}}"
						),
						System::Get().Evaluate("pair {{5}6}{}")
					);

					BOOST_CHECK_EQUAL(
						"{{2}{3}}",
						System::Get().Evaluate("pair {{2}}{3}")
					);

					BOOST_CHECK_EQUAL(
						"{{2}{3}}",
						System::Get().Evaluate("pair quote{2}{3}")
					);

					BOOST_CHECK_EQUAL(
						"{2{{3}}}",
						System::Get().Evaluate("pair{2}quote{3}")
					);
				}

			BOOST_AUTO_TEST_SUITE_END()

		}

	}
	
}

	#endif

#else

	#include "om/language/operation/quote_operation.hpp"

// MARK: - Om::Language::Operation::PairOperation

	#define Type_ \
	Om::Language::Operation::PairOperation

// MARK: public (static)

inline char const * Type_::GetName() {
	return Om_Language_Operation_PairOperation_GetName_();
}

template <typename ThePairOperation>
inline void Type_::GiveElements(
	ThePairOperation & thePairOperation,
	Consumer & theConsumer
) {
	theConsumer.TakeElement(
		GetOperator()
	);
	if (
		!thePairOperation.thisExpression.IsEmpty()
	) {
		theConsumer.TakeQuotedElements(thePairOperation.thisExpression);
	}
}

// MARK: public (non-static)

inline Type_::PairOperation():
thisExpression() {}

template <typename TheOperand>
inline bool Type_::TakeOperand(
	Evaluation & theEvaluation,
	TheOperand & theOperand
) {
	assert(
		!theOperand.IsEmpty()
	);
	if (
		this->thisExpression.IsEmpty()
	) {
		this->thisExpression.TakeElements(*theOperand);
		if (
			this->thisExpression.IsEmpty()
		) {
			QuoteOperation::Give(theEvaluation);
			return true;
		}
		return false;
	}
	this->thisExpression.TakeOperand(theOperand);
	theEvaluation.TakeQuotedProducer(this->thisExpression);
	return true;
}

template <typename TheProducer>
inline bool Type_::TakeQuotedProducer(
	Evaluation & theEvaluation,
	TheProducer & theProducer
) {
	if (
		this->thisExpression.IsEmpty()
	) {
		this->thisExpression.TakeElements(theProducer);
		if (
			this->thisExpression.IsEmpty()
		) {
			QuoteOperation::Give(theEvaluation);
			return true;
		}
		return false;
	}
	this->thisExpression.TakeQuotedProducer(theProducer);
	theEvaluation.TakeQuotedProducer(this->thisExpression);
	return true;
}

	#undef Type_

#endif
