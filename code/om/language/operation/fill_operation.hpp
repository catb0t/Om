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

\defgroup om__operation__fill_operation__ fill
	\ingroup om__operation__
	\brief
		"Fills" an \ref om__expression__ such that none of its \ref om__operator__ "Operators" is not followed by an \ref om__operand__.
	\par Input
		<tt>{expression} ...</tt>
	\par Output
		<tt>{expression}</tt>
	\par Examples
		<table>
			<tr>
				<td><tt><b>fill {A B{2} C} {1} {3}</b></tt></td>
			</tr>
			<tr>
				<td><tt><em>{A{1}<br/>
				B{2}<br/>
				C{3}}</em></tt></td>
			</tr>
		</table>
	\par Implementation
		Om::Language::Operation::FillOperation

	For each \ref om__operator__ in an \ref om__expression__ that has no \ref om__operand__ following it, pulls the next \ref om__operand__ following the \ref om__expression__ and inserts it after the \ref om__operator__.
*/

#ifndef Om_Language_Operation_FillOperation_

	#define Om_Language_Operation_FillOperation_ \
	Om::Language::Operation::FillOperation

	#include "om/language/expression.hpp"
	#include "om/language/operation/default_incomplete_operation.hpp"
	#include "om/language/system.hpp"

	#define Om_Language_Operation_FillOperation_GetName_() \
	"fill"

namespace Om {

	namespace Language {

		namespace Operation {

			// MARK: - Om::Language::Operation::FillOperation

			/*!
			\brief
				The \ref om__operation__fill_operation__ operation implementation.
			*/
			class FillOperation:
			public DefaultIncompleteOperation<FillOperation> {

			public: // MARK: public (static)

				static char const * GetName();

				template <typename TheFillOperation>
				static void GiveElements(
					TheFillOperation &,
					Consumer &
				);

			public: // MARK: public (non-static)

				FillOperation();

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

			private: // MARK: private (static)

				typedef Expression::FormRange<Form> FormRange;

			private: // MARK: private (non-static)

				/*!
				\brief
					The output argument that is being filled.
				*/
				Expression thisExpression;

				/*!
				\brief
					The current position in the output argument.
				*/
				boost::optional<FormRange> thisFormRange;

			};

			namespace {

				static System::Definition<FillOperation> const theFillDefinition;

			}

		}

	}

}

	#include "om/language/operation/fill_operation.cpp"

#endif
