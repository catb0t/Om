/*!
\file
	\brief
		<a href="http://github.com/sparist/Om">Om</a> header file.
	\version
		0.1.3
	\date
		2012-2014
	\copyright
		Copyright (c) <a href="http://sparist.com">Sparist</a>. All rights reserved. This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\author
		Jason Erb

\defgroup om__operation__dequote_operation__ dequote
	\ingroup om__operation__
	\brief
		Strips the outer braces from an \ref om__operand__.
	\par Input
		<tt>{A}</tt>
	\par Output
		<tt>A</tt>
	\par Implementation
		Om::Language::Operation::DequoteOperation
*/

#ifndef Om_Language_Operation_DequoteOperation_

	#define Om_Language_Operation_DequoteOperation_ \
	Om::Language::Operation::DequoteOperation

	#include "om/language/operation/default_incomplete_operation.hpp"
	#include "om/language/system.hpp"

	#define Om_Language_Operation_DequoteOperation_GetName_() \
	"dequote"

namespace Om {

	namespace Language {

		namespace Operation {

			// MARK: - Om::Language::Operation::DequoteOperation

			/*!
			\brief
				The \ref om__operation__dequote_operation__ operation implementation.
			*/
			class DequoteOperation:
			public DefaultIncompleteOperation<DequoteOperation> {

			public: // MARK: public (static)

				static char const * GetName();

				template <typename TheDequoteOperation>
				static void GiveElements(
					TheDequoteOperation &,
					Consumer &
				);

			public: // MARK: public (non-static)

				template <typename TheOperand>
				bool TakeOperand(
					Evaluation &,
					TheOperand &
				);

				template <typename TheProducer>
				bool TakeQuotedProducer(
					Evaluation &,
					TheProducer &
				);

			};

			namespace {

				static System::Definition<DequoteOperation> const theDequoteDefinition;

			}

		}

	}

}

	#include "om/language/operation/dequote_operation.cpp"

#endif
