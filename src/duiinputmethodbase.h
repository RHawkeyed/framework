/* * This file is part of dui-im-framework *
 *
 * Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 * Contact: Nokia Corporation (directui@nokia.com)
 *
 * If you have questions regarding the use of this file, please contact
 * Nokia at directui@nokia.com.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation
 * and appearing in the file LICENSE.LGPL included in the packaging
 * of this file.
 */

#ifndef DUIINPUTMETHODBASE_H
#define DUIINPUTMETHODBASE_H

#include <QObject>
#include <DuiNamespace>
#include "duiimhandlerstate.h"

class QRegion;
class QPoint;
class QRect;
class QGraphicsScene;
class DuiInputContextConnection;
class DuiInputMethodBasePrivate;

/*!
 * \class DuiInputMethodBase
 *
 * \brief DuiInputMethodBase is a base class for input method servers.
 * It defines the interface which input context connection classes can use for
 * passing commands received from the applications
 */
class DuiInputMethodBase: public QObject
{
    Q_OBJECT

public:
    /*! Constructor for input method base
     * \param icConnection input context connection class, not owned by input method base
     */
    DuiInputMethodBase(DuiInputContextConnection *icConnection, QObject *parent = 0);

    ~DuiInputMethodBase();

    /*! \brief Returns input context connection associated with this input method base
     */
    DuiInputContextConnection *inputContextConnection() const;

    /*! \brief Shows the input method.
     */
    virtual void show();

    /*! \brief Hides the input method
     */
    virtual void hide();

    /*! \brief Sets preedit string of the input method server
     */
    virtual void setPreedit(const QString &preeditString);

    /*! \brief Update input method server state
     */
    virtual void update();

    /*! \brief Resets input method server state
     */
    virtual void reset();

    /*! \brief Notifies input method server about mouse click on the preedit string
     */
    virtual void mouseClickedOnPreedit(const QPoint &pos, const QRect &preeditRect);

    /*! \brief Notifies that the focus widget in application changed visualization priority
     */
    virtual void visualizationPriorityChanged(bool priority);

    /*! \brief Target application changed orientation. Input method usually changes its
     *         own orientation according to this.
     */
    virtual void appOrientationChanged(int angle);

    /*! \brief Set copy/paste button state: hide it, show copy or show paste
     *  \param copyAvailable bool TRUE if text is selected
     *  \param pasteAvailable bool TRUE if clipboard content is not empty
     */
    virtual void setCopyPasteButton(bool copyAvailable, bool pasteAvailable);

    /*!
     * \brief use a custom toolbar
     */
    virtual void useToolbar(const QString &);

    /*!
     * \brief compose the input raw key event for Chinese Input which comes from hardware keyboard.
     */
    virtual void composeTextInput(int keyType, int keyCode, int modifier, const QString &text,
                                  bool autoRepeat, int count, int nativeScanCode);

    /*!
     * \brief Redirects key events from hardware keyboard of all keys which have been registered
     * with \sa DuiInputContextConnection::addRedirectedKey().
     */
    virtual void redirectKey(int keyType, int keyCode, const QString &text);

    /* \brief This method is called when keyboard status is changed:
     * hardware keyboard is opened or closed, BT keyboard is connected
     * or disconnected
     * \param state const QList<DuiIMHandlerState>& list of current states
     * for this plugin
     */
    virtual void setState(const QList<DuiIMHandlerState> &state);

signals:
    /*!
     * Inform that the screen area covered by the input method has been changed.
     *
     * \param region the new region
     */
    void regionUpdated(const QRegion &region);

    /*!
     * Inform that the part of the screen area covered by the input method that
     * should be avoided by the screen area receiving input in order not to be
     * obscured has been changed.
     *
     * For now this region must be so simple that its bounding box can be
     * effectively used as the avoidance area.
     *
     * \param region the new region
     */
    void inputMethodAreaUpdated(const QRegion &region);

private:
    Q_DISABLE_COPY(DuiInputMethodBase)

    DuiInputMethodBasePrivate *d;
};

#endif
