/* Copyright (c) 2006-2015, Universities Space Research Association (USRA).
 *  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Universities Space Research Association nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY USRA ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL USRA BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

package gov.nasa.luv;

import java.util.Enumeration;

/**
 * This class was modeled after the CheckNodeTreeExample, CheckNode, CheckRenerer
 * classes from Tame Swing examplescreated by Nobuo Tamemasa.
 *
 * http://devdaily.com/java/swing/tame/
 * 
@author Nobuo Tamemasa
@version 1.0 01/11/99
*/

class CheckNode
    extends javax.swing.tree.DefaultMutableTreeNode {

    protected boolean isSelected;

    public CheckNode() {
        this(null);
    }

    public CheckNode(Object userObject) {
        this(userObject, true, false);
    }

    public CheckNode(Object userObject,
                     boolean allowsChildren,
                     boolean isSelected) {
        super(userObject, allowsChildren);
    }

    public void setSelected(boolean isSelected) {
        this.isSelected = isSelected;

        if (children != null) {
            java.util.Enumeration e = children.elements();
            while (e.hasMoreElements()) {
                CheckNode node = (CheckNode) e.nextElement();
                node.setSelected(isSelected);
            }
        }
    }

    public boolean isSelected() {
        return isSelected;
    }
}

