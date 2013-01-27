/*!
\file
	\brief
		Om hpp file.
	\version
		0.1.2
	\date
		2012-2013
	\copyright
		Copyright (c) Jason Erb.  All rights reserved.  This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.
*/

#if !defined( Om_Operations_DequoteOperation_ )

	#define Om_Operations_DequoteOperation_ \
	Om::Operations::DequoteOperation

	#include "om/default_operation.hpp"
	#include "om/definition.hpp"

	#define Om_Operations_DequoteOperation_GetName_() \
	"dequote"

namespace Om
{
	namespace Operations
	{
		// MARK: - Om::Operations::DequoteOperation
		/*!
		\brief
			The \ref dequote_operation Operation implementation.
		*/
		struct DequoteOperation
		:
		DefaultOperation< DequoteOperation >
		{
		public: // MARK: public (static)

			static char const * GetName();

			template< typename TheDequoteOperation >
			static void GiveElements(
				TheDequoteOperation &,
				Queue &
			);

		public: // MARK: public (non-static)

			template< typename TheOperand >
			bool TakeOperand(
				Evaluation &,
				TheOperand &
			);

			template< typename TheQueue >
			bool TakeQuotedQueue(
				Evaluation &,
				TheQueue &
			);
		};

		namespace
		{
			static Definition< DequoteOperation > const theDequoteDefinition;
		}
	}
}

	#include "om/operations/dequote_operation.cpp"

#endif
