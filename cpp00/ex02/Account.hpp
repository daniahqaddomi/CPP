/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:07:51 by dqaddomi          #+#    #+#             */
/*   Updated: 2025/11/20 12:14:05 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

class Account
{
public:
	// Type definitions
	typedef Account t;

	// Constructors and destructor
	Account(int initial_deposit);
	~Account(void);

	// Static member functions
	static int	getNbAccounts(void);
	static int	getTotalAmount(void);
	static int	getNbDeposits(void);
	static int	getNbWithdrawals(void);
	static void	displayAccountsInfos(void);

	// Member functions
	void	makeDeposit(int deposit);
	bool	makeWithdrawal(int withdrawal);
	int		checkAmount(void) const;
	void	displayStatus(void) const;

private:
	// Static private members
	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	// Private member function
	static void	_displayTimestamp(void);

	// Instance private members
	int	_accountIndex;
	int	_amount;
	int	_nbDeposits;
	int	_nbWithdrawals;
};

#endif
