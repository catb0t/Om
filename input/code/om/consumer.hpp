/*!
\file
	\brief
		<a href="http://om-language.org">Om</a> header file.
	\version
		0.1.2
	\date
		2012-2013
	\copyright
		Copyright (c) <a href="http://sparist.com">Sparist</a>. All rights reserved. This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.
*/

#ifndef Om_Consumer_

	#define Om_Consumer_ \
	Om::Consumer

namespace Om {

	//! \cond
	class Null;

	class Operand;

	class Operator;

	class Parser;

	class Producer;

	class Separator;
	//! \endcond

	/*!
	\brief
		An Element taker; takes at the back.
	*/
	class Consumer {

	public: // MARK: public (non-static)

		virtual ~Consumer() = 0;

		virtual void ReadElements(Parser &) = 0;

		virtual void ReadQuotedElements(Parser &) = 0;

		/*!
		\brief
			Takes a Null Element, which is disregarded.
		*/
		void TakeElement(Null &);

		/*!
		\brief
			\overload
		*/
		void TakeElement(Null const &);

		/*!
		\brief
			Takes a non-empty Element, which gets copied or swapped.
		\pre
			The Element argument is non-empty.

		It is up to the implementation to decide how to process an Element. Each Element is processed eagerly, meaning that two Operators received consecutively may be processed differently than the receipt of one Operator comprised of a concatenation of both.
		*/
		virtual void TakeElement(Operand &) = 0;

		/*!
		\brief
			\overload
		*/
		virtual void TakeElement(Operand const &) = 0;

		/*!
		\brief
			\overload
		*/
		virtual void TakeElement(Operator &) = 0;

		/*!
		\brief
			\overload
		*/
		virtual void TakeElement(Operator const &) = 0;

		/*!
		\brief
			\overload
		*/
		virtual void TakeElement(Separator &) = 0;

		/*!
		\brief
			\overload
		*/
		virtual void TakeElement(Separator const &) = 0;

		/*!
		\brief
			Takes each Element of the argument.
		*/
		virtual void TakeElements(Producer &) = 0;

		/*!
		\brief
			\overload
		*/
		virtual void TakeElements(Producer const &) = 0;

		/*!
		\brief
			Constructs and takes an Operand, which takes each Element from the argument Producer.
		*/
		virtual void TakeQuotedElements(Producer &) = 0;

		/*!
		\brief
			\overload
		*/
		virtual void TakeQuotedElements(Producer const &) = 0;

	private: // MARK: private (non-static)

		Consumer & operator =(Consumer const &);

	};

}

	#include "om/consumer.cpp"

#endif