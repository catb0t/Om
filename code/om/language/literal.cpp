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

#ifndef Om_Language_Literal_

	#include "om/language/literal.hpp"

	#ifdef Om_Macro_Test_

		#include "om/language/system.hpp"

		#ifndef Om_Macro_Precompilation_

			#include "boost/test/unit_test.hpp"

		#endif

namespace Om {

	namespace Language {

		BOOST_AUTO_TEST_SUITE(LiteralTest)

			BOOST_AUTO_TEST_CASE(EqualityTest) {
				// Positive match
				BOOST_CHECK_EQUAL(
					"{{a{b}{c}\nd{e}}}",
					System::Get().Evaluate("= {a{b}{c}\nd{e}} {a{b}{c}\nd{e}}")
				);

				// Negative match
				BOOST_CHECK_EQUAL(
					"{}",
					System::Get().Evaluate("= {a{b}{c}} {a{b}{d}}")
				);

				// Empty match
				BOOST_CHECK_EQUAL(
					"{}",
					System::Get().Evaluate("= {} {a{b}{c}}")
				);

				// Empty match
				BOOST_CHECK_EQUAL(
					"{{}}",
					System::Get().Evaluate("= {} {}")
				);
			}

			BOOST_AUTO_TEST_CASE(RecursionTest) {
				size_t const theDepth = 50000;

				std::string theString;
				for (
					size_t theLevel = theDepth;
					theLevel;
					--theLevel
				) {
					theString = "{" + theString + "}";
				}

				Om::Source::CodePointSource<std::string::const_iterator> theCodePointSource(
					theString.begin(),
					theString.end()
				);
				Reader theReader(theCodePointSource);
				Literal theLiteral;
				theLiteral.ParseElements(theReader);

				Literal theCopy;
				theCopy = theLiteral;

				theCopy.Clear();
				BOOST_CHECK(
					theCopy.IsEmpty()
				);
			}

		BOOST_AUTO_TEST_SUITE_END()

	}

}

	#endif

#else

	#include "om/language/operator.hpp"
	#include "om/language/separator.hpp"

	#ifndef Om_Macro_Precompilation_

		#include <stack>

	#endif

// MARK: - Om::Language::Literal

	#define Type_ \
	Om::Language::Literal

// MARK: public (static)

inline char const * Type_::GetName() {
	return Om_Language_Literal_GetName_();
}

// MARK: public (non-static)

inline Type_::~Literal() {
	// Flatten the ElementDeque to avoid recursive destructor calls.
	try {
		while (
			!this->thisElementDeque.empty()
		) {
			std::auto_ptr<Element> theElement(
				this->thisElementDeque.pop_front().release()
			);
			assert(
				theElement.get()
			);
			(*theElement)->GiveElements(*this);
		}
	} catch (...) {}
}

inline Type_::Literal():
thisElementDeque() {}

inline Type_ & Type_::operator =(Literal theLiteral) {
	this->Swap(theLiteral);
	return *this;
}

template <typename TheElement>
inline void Type_::BackGive(Consumer & theConsumer) {
	if (
		!this->thisElementDeque.empty() &&
		dynamic_cast<TheElement const *>(
			&this->thisElementDeque.back()
		)
	) {
		this->thisElementDeque.pop_back()->GiveElements(theConsumer);
	}
}

inline void Type_::BackGiveElement(Consumer & theConsumer) {
	if (
		!this->thisElementDeque.empty()
	) {
		this->thisElementDeque.pop_back()->GiveElements(theConsumer);
	}
}

inline void Type_::Clear() {
	this->thisElementDeque.clear();
}

template <typename TheElement>
inline void Type_::FrontGive(Consumer & theConsumer) {
	if (
		!this->thisElementDeque.empty() &&
		dynamic_cast<TheElement const *>(
			&this->thisElementDeque.front()
		)
	) {
		this->thisElementDeque.pop_front()->GiveElements(theConsumer);
	}
}

inline void Type_::FrontGiveElement(Consumer & theConsumer) {
	if (
		!this->thisElementDeque.empty()
	) {
		this->thisElementDeque.pop_front()->GiveElements(theConsumer);
	}
}

inline std::auto_ptr<
	Om::Source::Source<Om::Language::Element>
> Type_::GetElementRange() {
	return std::auto_ptr<
		Om::Source::Source<Element>
	>(
		new ElementRange<Literal>(*this)
	);
}

inline std::auto_ptr<
	Om::Source::Source<Om::Language::Element const>
> Type_::GetElementRange() const {
	return std::auto_ptr<
		Om::Source::Source<Element const>
	>(
		new ElementRange<Literal const>(*this)
	);
}

inline void Type_::GiveElements(Consumer & theConsumer) {
	this->GiveElements(
		theConsumer,
		this->thisElementDeque.begin(),
		this->thisElementDeque.end()
	);
	this->thisElementDeque.clear();
}

inline void Type_::GiveElements(Consumer & theConsumer) const {
	this->GiveElements(
		theConsumer,
		this->thisElementDeque.begin(),
		this->thisElementDeque.end()
	);
}

inline bool Type_::IsEmpty() const {
	return this->thisElementDeque.empty();
}

inline void Type_::ParseElements(Reader & theReader) {
	std::stack<Literal *> theStack;
	theStack.push(this);

	while (theReader) {
		switch (*theReader) {
		case Symbol::theEndOperandSymbol:
			assert(
				!theStack.empty() &&
				this != theStack.top()
			);
			theStack.pop();
			break;
		case Symbol::theStartOperandSymbol:
			{
				std::auto_ptr<Literal> theLiteral(new Literal);
				Literal * theLiteralPointer = theLiteral.get();
				{
					Operand theOperand(theLiteral);
					theStack.top()->TakeOperand(theOperand);
				}
				theStack.push(theLiteralPointer);
			}
			break;
		Om_Language_Symbol_SeparatorSymbol_GetCases_():
			assert(
				!theStack.empty() &&
				theStack.top()
			);
			{
				Separator theSeparator(theReader);
				theStack.top()->TakeSeparator(theSeparator);
			}
			continue;
		default:
			assert(
				!theStack.empty() &&
				theStack.top()
			);
			{
				Operator theOperator(theReader);
				theStack.top()->TakeOperator(theOperator);
			}
			continue;
		}
		theReader.Pop();
	}
}

inline void Type_::ParseQuotedElements(Reader & theReader) {
	Literal theLiteral;
	theLiteral.ParseElements(theReader);
	this->TakeQuotedProducer(theLiteral);
}

inline void Type_::Swap(Literal & theLiteral) {
	this->thisElementDeque.swap(theLiteral.thisElementDeque);
}

template <typename TheOperand>
inline void Type_::TakeOperand(TheOperand & theOperand) {
	assert(
		!theOperand.IsEmpty()
	);
	this->thisElementDeque.push_back(
		Give(theOperand)
	);
}

template <typename TheOperator>
inline void Type_::TakeOperator(TheOperator & theOperator) {
	assert(
		!theOperator.IsEmpty()
	);
	this->TakeAtom(theOperator);
}

template <typename TheProducer>
inline void Type_::TakeQuotedProducer(TheProducer & theProducer) {
	this->thisElementDeque.push_back(
		new Operand(
			theProducer.GiveProgram()
		)
	);
}

template <typename TheSeparator>
inline void Type_::TakeSeparator(TheSeparator & theSeparator) {
	assert(
		!theSeparator.IsEmpty()
	);
	this->TakeAtom(theSeparator);
}

// MARK: private (static)

template <typename TheElementIterator>
inline void Type_::GiveElements(
	Consumer & theConsumer,
	TheElementIterator theCurrent,
	TheElementIterator const theEnd
) {
	for (
		;
		theEnd != theCurrent;
		++theCurrent
	) {
		theCurrent->GiveElements(theConsumer);
	}
}

// MARK: private (non-static)

template <typename TheAtom>
inline void Type_::TakeAtom(TheAtom & theAtom) {
	assert(
		!theAtom.IsEmpty()
	);
	if (
		this->thisElementDeque.empty() ||
		!this->thisElementDeque.back().Merge(theAtom)
	) {
		this->thisElementDeque.push_back(
			Give(theAtom)
		);
	}
}

	#undef Type_

// MARK: - Om::Language::Literal::ElementRange

	#define Type_ \
	Om::Language::Literal::ElementRange

// MARK: public (non-static)

inline Type_<Om::Language::Literal>::ElementRange(Literal & theLiteral):
Om::Source::CollectionFrontSource<
	Element,
	ElementDeque::iterator
>(theLiteral.thisElementDeque) {}

inline Type_<Om::Language::Literal const>::ElementRange(Literal const & theLiteral):
Om::Source::CollectionFrontSource<
	Element const,
	ElementDeque::const_iterator
>(theLiteral.thisElementDeque) {}

	#undef Type_

// MARK: - boost::

template <>
inline void boost::swap(
	Om::Language::Literal & theFirst,
	Om::Language::Literal & theSecond
) {
	theFirst.Swap(theSecond);
}

#endif
