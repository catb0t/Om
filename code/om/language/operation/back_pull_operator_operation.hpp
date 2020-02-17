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

\defgroup om__operation__back_pull_operator_operation__ [...operator]->
	\ingroup om__operation__
	\brief
		Pops the last \ref om__operator__ (if any), quoted.
	\par Input
		<tt>{A B}</tt>
	\par Output
		<tt>{B} {A }</tt>
	\par Implementation
		Om::Language::Operation::BackPullOperatorOperation
*/

#ifndef Om_Language_Operation_BackPullOperatorOperation_

	#define Om_Language_Operation_BackPullOperatorOperation_ \
	Om::Language::Operation::BackPullOperatorOperation

	#include "om/language/system.hpp"

	#define Om_Language_Operation_BackPullOperatorOperation_GetName_() \
	"[...operator]->"

namespace Om {

	namespace Language {

		//! \cond
		class Literal;
		//! \endcond

		namespace Operation {

			// MARK: - Om::Language::Operation::BackPullOperatorOperation

			/*!
			\brief
				The \ref om__operation__back_pull_operator_operation__ operation implementation.
			*/
			class BackPullOperatorOperation {

			public: // MARK: public (static)

				static char const * GetName();

				static void Give(Evaluation &);

				/*!
				\brief
					The callback for PullOperation.
				*/
				template <typename TheConsumer>
				static void Pull(
					Literal &,
					TheConsumer &
				);

			};

			namespace {

				static System::Definition<BackPullOperatorOperation> const theBackPullOperatorDefinition;

			}

		}

	}

}

	#include "om/language/operation/back_pull_operator_operation.cpp"

#endif