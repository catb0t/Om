/*!
\file
	\brief
		<a href="http://github.com/sparist/Om">Om</a> source file.
	\version
		0.1.3
	\date
		2012-2014
	\copyright
		Copyright (c) <a href="http://sparist.com">Sparist</a>. All rights reserved. This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\author
		Jason Erb
*/

#ifndef Om_Source_IteratorPairSource_

	#include "om/source/iterator_pair_source.hpp"

#else

// MARK: - Om::Source::IteratorPairSource

	#define Template_ \
	template < \
		typename ThisItem, \
		typename ThisIterator \
	>

	#define Type_ \
	Om::Source::IteratorPairSource< \
		ThisItem, \
		ThisIterator \
	>

// MARK: public (non-static)

Template_
inline Type_::IteratorPairSource(
	ThisIterator theCurrent,
	ThisIterator const theEnd
):
thisCurrent(theCurrent),
thisEnd(theEnd) {}

Template_
inline Type_ & Type_::operator =(IteratorPairSource theIteratorPairSource) {
	this->Swap(theIteratorPairSource);
	return *this;
}

Template_
inline bool Type_::operator !() const {
	return this->thisEnd == this->thisCurrent;
}

Template_
inline ThisItem & Type_::operator *() const {
	assert(this->thisEnd != this->thisCurrent);
	return *this->thisCurrent;
}

Template_
inline bool Type_::Equals(IteratorPairSource const & theIteratorPairSource) const {
	return this->thisCurrent == theIteratorPairSource.thisCurrent;
}

Template_
inline void Type_::End() {
	this->thisCurrent = this->thisEnd;
}

Template_
inline void Type_::Pop() {
	assert(this->thisEnd != this->thisCurrent);
	++this->thisCurrent;
}

Template_
inline void Type_::Swap(IteratorPairSource & theIteratorPairSource) {
	boost::swap(
		this->thisCurrent,
		theIteratorPairSource.thisCurrent
	);
	boost::swap(
		this->thisEnd,
		theIteratorPairSource.thisEnd
	);
}

	#undef Type_
	#undef Template_

// MARK: - Om::Source::

	#define Template_ \
	template < \
		typename TheItem, \
		typename TheIterator \
	>

	#define Type_ \
	Om::Source::IteratorPairSource< \
		TheItem, \
		TheIterator \
	>

Template_
inline bool Om::Source::operator ==(
	Type_ const & theFirst,
	Type_ const & theSecond
) {
	return theFirst.Equals(theSecond);
}

Template_
inline bool Om::Source::operator !=(
	Type_ const & theFirst,
	Type_ const & theSecond
) {
	return !theFirst.Equals(theSecond);
}

// MARK: - boost::

Template_
inline void boost::swap(
	Type_ & theFirst,
	Type_ & theSecond
) {
	theFirst.Swap(theSecond);
}

	#undef Type_
	#undef Template_

#endif
