/*!
\file
	\brief
		Om hpp file.
	\version
		0.1.1
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
*/
#if !defined( Om_Operations_PullOperation_ )
	#define Om_Operations_PullOperation_ Om::Operations::PullOperation

	#include "om/default_operation.hpp"

namespace Om
{
	namespace Operations
	{
		// MARK: - Om::Operations::PullOperation
		/*!
		\brief
			An Operation that pulls part of a Program.
		*/
		template< typename ThisProgram, typename ThisImplementation >
		struct PullOperation
		:
		DefaultOperation< PullOperation< ThisProgram, ThisImplementation > >
		{
		public: // MARK: public (static)

			template< typename ThePullOperation >
			static void GiveElements( ThePullOperation &, Queue & );

		public: // MARK: public (non-static)

			virtual bool ReadQuotedElements( Evaluation &, Parser & );

			template< typename TheOperand >
			bool TakeOperand( Evaluation &, TheOperand & );

			template< typename TheQueue >
			bool TakeQuotedQueue( Evaluation &, TheQueue & );

		private: // MARK: private (static)

			static Operator const & GetOperator();
		};
	}
}

	#include "om/operations/pull_operation.cpp"
#endif