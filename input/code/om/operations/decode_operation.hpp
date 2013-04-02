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

#ifndef Om_Operations_DecodeOperation_

	#define Om_Operations_DecodeOperation_ \
	Om::Operations::DecodeOperation

	#include "om/default_operation.hpp"
	#include "om/system.hpp"

	#define Om_Operations_DecodeOperation_GetName_() \
	"decode"

namespace Om {

	namespace Operations {

		// MARK: - Om::Operations::DecodeOperation

		/*!
		\brief
			The \ref om__operations__decode_operation__ operation implementation.
		*/
		class DecodeOperation:
		public DefaultOperation<DecodeOperation> {

		public: // MARK: public (static)

			static char const * GetName();

			template <typename TheDecodeOperation>
			static void GiveElements(
				TheDecodeOperation &,
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

			static System::Definition<DecodeOperation> const theDecodeDefinition;

		}

	}

}

	#include "om/operations/decode_operation.cpp"

#endif