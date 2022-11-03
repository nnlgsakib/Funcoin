// Copyright (c) 2011-2020 The Funcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef FUNCOIN_QT_FUNCOINADDRESSVALIDATOR_H
#define FUNCOIN_QT_FUNCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class FuncoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit FuncoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** Funcoin address widget validator, checks for a valid bitcoin address.
 */
class FuncoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit FuncoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // FUNCOIN_QT_FUNCOINADDRESSVALIDATOR_H
