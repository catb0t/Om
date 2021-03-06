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
*/

#ifndef Om_Language_Operation_TranslateOperation_

	#define Om_Language_Operation_TranslateOperation_ \
	Om::Language::Operation::TranslateOperation

	#include "om/language/lexicon.hpp"
	#include "om/language/operation/default_incomplete_operation.hpp"

namespace Om {

	namespace Language {

		namespace Operation {

			// MARK: - Om::Language::Operation::TranslateOperation

			/*!
			\brief
				An Operation that applies each Translator to a Program.
			*/
			template <typename ThisImplementation>
			class TranslateOperation:
			public DefaultIncompleteOperation<ThisImplementation> {

			public: // MARK: public (static)

				template <typename TheTranslateOperation>
				static void GiveElements(
					TheTranslateOperation &,
					Consumer &
				);

			public: // MARK: public (non-static)

				virtual ~TranslateOperation() = 0;

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

			protected: // MARK: protected (non-static)

				TranslateOperation();

				boost::optional<Lexicon> thisLexicon;

			};

		}

	}

}

	#include "om/language/operation/translate_operation.cpp"

#endif
