// Copyright (c) 2018 The Costly Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("costly:CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a?req-dontexist="));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("costly:CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a?dontexist="));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("costly:CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a?label=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a"));
    QVERIFY(rv.label == QString("Some Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("costly:CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a?amount=0.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("costly:CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a?amount=1.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("costly:CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a?amount=100&label=Some Example"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Some Example"));

    uri.setUrl(QString("costly:CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a?message=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseBitcoinURI("costly://CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a?message=Some Example Address", &rv));
    QVERIFY(rv.address == QString("CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("costly:CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a?req-message=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("costly:CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a?amount=1,000&label=Some Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("costly:CeWDnCxKgCXTTgwBC22r8vn7pFCYUmc96a?amount=1,000.0&label=Some Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));
}
