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
*/
#if !defined( Om_Translator_ )
	#define Om_Translator_ Om::Translator

	#include "om/code_point.hpp"

namespace Om
{
	//! \cond
	struct Evaluation;

	struct Operator;

	template< typename ThisItem >
	struct Sink;

	template< typename ThisItem >
	struct Source;

	struct Queue;
	//! \endcond

	// MARK: - Om::Translator
	/*!
	\brief
		An Operator lookup for use by an Evaluator.
	*/
	struct Translator
	{
	public: // MARK: public (non-static)

		/*!
		\brief
			Evaluates input from the #CodePoint Source and pushes it to the
			#CodePoint Sink.
		*/
		void Evaluate(
			Source< CodePoint const > &,
			Sink< CodePoint const > &
		) const;

		/*!
		\brief
			A convenience overload that evaluates input from the string and
			returns the output string.
		\param theCodeUnitIterator
			A non-null pointer to a null-terminated code unit array.
		\return
			A string containing the output.

		This form is implemented in terms of the other form.
		*/
		std::string Evaluate( char const theCodeUnitIterator[] ) const;

		virtual void GiveElements( Queue & ) const = 0;

		virtual bool IsEmpty() const = 0;

		/*!
		\brief
			Translates the Operator to an object that is then given to the
			Evaluation.
		\return
			True if the Operator was found.
		*/
		virtual bool Translate( Evaluation &, Operator const & ) const = 0;
	};
}

	#include "om/translator.cpp"
#endif