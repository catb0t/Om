/*!
\file
	\brief
		Om hpp file.
	\version
		0.1
	\date
		2012
	\copyright
		Copyright (c) Jason Erb.
		All rights reserved.  This program and the accompanying materials are
		made available under the terms of the
		<a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse
		Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.

\defgroup expression_front_push_operation ->expression
	\ingroup operations
	\brief
		Pushes the contents of an \ref operand onto the front of an
		\ref expression (quoted).
	\par Input
		<tt>{A} {B}</tt>
	\par Output
		<tt>{A<br/>
		B}</tt>
	\par Implementation
		Om#Operations#ExpressionFrontPushOperation
*/
#if !defined( Om_Operations_ExpressionFrontPushOperation_ )
	#define Om_Operations_ExpressionFrontPushOperation_ \
	Om::Operations::ExpressionFrontPushOperation

	#include "om/definition.hpp"

	#define Om_Operations_ExpressionFrontPushOperation_GetName_() "->expression"

namespace Om
{
	namespace Operations
	{
		// MARK: - Om::Operations::ExpressionFrontPushOperation
		/*!
		\brief
			The \ref expression_front_push_operation Operation implementation.
		*/
		struct ExpressionFrontPushOperation
		{
		public: // MARK: public (static)

			static char const * GetName();

			template< typename TheEvaluator >
			static void Give( TheEvaluator & );
		};

		namespace
		{
			static Definition<
				ExpressionFrontPushOperation
			> const theExpressionFrontPushDefinition;
		}
	}
}

	#include "om/operations/expression_front_push_operation.cpp"
#endif
