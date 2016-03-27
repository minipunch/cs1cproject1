#ifndef EXECUTIVE_H_
#define EXECUTIVE_H_

#include "member.h"
/*!
 * \brief Represents an executive member
 *
 * Inherits from member, represents an executive member in the store
 */
class executive : public member {
private:
	float rebateAmount;
public:
	// constructors
    /*!
     * \brief default constructor
     */
	executive();
    /*!
     * \brief destructor
     */
	virtual ~executive();
    /*!
     * \brief non-default constructor
     * \param newRebate the rebate to set
     */
	executive(float newRebate);
	// setters
    /*!
     * \brief sets the rebate amount
     *
     * Utility: manually set the rebate ratefor an exectutive
     * \param num
     */
	void setRebateAmount(float num);
    /*!
     * \brief sets all of the attributes of an executive object
     * \param name     new name
     * \param type     type of member
     * \param id       new id number
     * \param exprDate new expiration date
     * \param rebate   new rebate
     */
	void setAll(string name, string type, double id, Date exprDate, float rebate);
    /*!
     * \brief gets the rebate rate
     * \return rebate rate
     */
	float getRebateAmount() const;
    /*!
     * \brief calculates the rebate
     */
    void calculateRebate() ;
    /*!
     * \brief prints and executive(not being used)
     */
	void printExecutive() const;
    /*!
     * \brief prints current rebate amount
     * \return stringstream of the output
     */
    virtual string printRebate();
    /*!
     * \brief renew membership
     *
     * adds the renewal cost of this membership to the running totals
     */
    virtual void renew();

    /*!
     * \file executive.h
     * \brief  Header for executive class
     *
     * This file contains all of the declarations of the executive class
     */

};

#endif /* EXECUTIVE_H_ */
