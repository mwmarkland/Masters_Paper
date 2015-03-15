% @(#)$Id: MoneyTrait.lsl,v 1.3 1997/07/30 04:54:57 leavens Exp $

MoneyTrait: trait
  includes MoneyBasics, DerivedOrders(Money)
  introduces
    __+__, __-__: Money, Money -> Money
    __*__: Q, Money -> Money
    __>__: Money, Money -> Bool
    MONEY_MAX, MONEY_MIN: -> Money
    inRange: Money -> Bool

  asserts
    \forall q: Q, p,p1,p2: long, m: Money
      pennies(p1) + pennies(p2) == pennies(p1 + p2);
      pennies(p1) - pennies(p2) == pennies(p1 - p2);
      q * pennies(p1) == pennies(floor(q * (p1/100)));
      pennies(p1) > pennies(p2) == p1 > p2;
      pennies(10000) < MONEY_MAX;
      MONEY_MIN < pennies(-10000);
      inRange(m) == MONEY_MIN <= m /\ m <= MONEY_MAX;

  implies
    TotalOrder(Money)
    \forall q,q1,q2: Q, p,p1,p2: long, m,m1,m2: Money
      pennies(100*dollars(m)) + pennies(cents(m)) == m;
      m1 > m2 == dollars(m1) > dollars(m2)
                 \/ (dollars(m1) = dollars(m2)
                     /\ cents(m1) > cents(m2));
    converts
      __+__: Money, Money -> Money,
      __-__: Money, Money -> Money,
      __*__: Q, Money -> Money,
      __>__: Money, Money -> Bool

  ------------------------------------------------------------------------

[Index]

HTML generated using lcpp2html.
