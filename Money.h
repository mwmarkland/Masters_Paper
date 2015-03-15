// @(#)$Id: Money.h,v 1.4 1997/07/30 20:41:01 leavens Exp $

#ifndef Money_h
#define Money_h

//@ uses MoneyTrait;
//@ uses NoContainedObjects(Money);

class Money
#include "Money.bse"
{
public:
  //@ invariant inRange(self\any);
  //@ constraint self' = self^;  // Money is immutable

  Money(double amt) throw();
  //@ behavior {
  //@   requires inRange(money(rational(amt)));
  //@   constructs self;
  //@   ensures self' = money(rational(amt));
  //@ }

  Money(long int cts = 0L) throw();
  //@ behavior {
  //@   requires inRange(pennies(cts));
  //@   constructs self;
  //@   ensures self' = pennies(cts);
  //@ }

  virtual ~Money() throw();
  //@ behavior {
  //@  ensures true;
  //@ }

  virtual long int Dollars() const throw();
  //@ behavior {
  //@   ensures result = dollars(self\any);
  //@ }

  virtual long int Cents() const throw();
  //@ behavior {
  //@   ensures result = cents(self\any);
  //@ }

  virtual Money & operator + (const Money & m2) const throw();
  //@ behavior {
  //@   requires assigned(m2, pre) /\ inRange(self\any + m2\any);
  //@   ensures returns;
  //@  also
  //@   requires assigned(m2, pre);
  //@   ensures liberally fresh(result) /\ assigned(result, post)
  //@                     /\ result' = self\any + m2\any;
  //@   example liberally self\any = money(300/1) /\ m2\any = money(400/1)
  //@                     /\ result' = money(700/1)
  //@                     /\ fresh(result) /\ assigned(result, post);
  //@ }

  virtual Money & operator - (const Money & m2) const throw();
  //@ behavior {
  //@   requires assigned(m2, pre) /\ inRange(self\any - m2\any);
  //@   ensures returns;
  //@  also
  //@   requires assigned(m2, pre);
  //@   ensures liberally fresh(result) /\ assigned(result, post)
  //@                     /\ result' = self\any - m2\any;
  //@ }

  virtual Money & operator * (double factor) const throw();
  //@ behavior {
  //@   requires inRange(rational(factor) * self\any);
  //@   ensures returns;
  //@  also
  //@   ensures liberally fresh(result) /\ assigned(result, post)
  //@           /\ result' = rational(factor) * self\any;
  //@ }

  virtual bool operator == (const Money & m2) const throw();
  //@ behavior {
  //@   requires assigned(m2, pre);
  //@   ensures result = (self\any = m2\any);
  //@   claims result = (dollars(self\any) = dollars(m2\any)
  //@                    /\ cents(self\any) = cents(m2\any));
  //@ }

  virtual bool operator > (const Money & m2) const throw();
  //@ behavior {
  //@   requires assigned(m2, pre);
  //@   ensures result = (self\any > m2\any);
  //@ }

  virtual bool operator >= (const Money & m2) const throw();
  //@ behavior {
  //@   requires assigned(m2, pre);
  //@   ensures result = (self\any >= m2\any);
  //@ }

  virtual bool operator < (const Money & m2) const throw();
  //@ behavior {
  //@   requires assigned(m2, pre);
  //@   ensures result = (self\any < m2\any);
  //@ }

  virtual bool operator <= (const Money & m2) const throw();
  //@ behavior {
  //@   requires assigned(m2, pre);
  //@   ensures result = (self\any <= m2\any);
  //@ }

#include "Money.pri"
};

#endif

  ------------------------------------------------------------------------

[Index]

HTML generated using lcpp2html.
