/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:47:15 by jko               #+#    #+#             */
/*   Updated: 2020/01/25 23:13:43 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	get_hex(int n)
{
	if (n < 10)
		return (char)(n + '0');
	return (char)(n + 87);
}

void	print_address(void *addr, int size)
{
	char	address[17];
	int		index;
	long	temp;

	address[16] = ':';
	index = 15;
	temp = addr;
	while (index >= 0)
	{
		address[index] = get_hex(temp % 16);
		temp /= 16;
		index--;
	}
	write(1, address, 17);
}

void	change_non_printable_and_print(void *addr, unsigned int size)
{
	char	temp;
	int		index;

	index = 0;
	while (index < size)
	{
		temp = *((char *)addr + index);
		if (temp >= 32 && temp <= 126)
			write(1, &temp, 1);
		else
			write(1, ".", 1);
		index++;
	}
}

void	print_contents(void *addr, unsigned int size, int space_size)
{
	char	temp_c[5];
	int		index;
	long	temp;

	index = 0;
	temp_c[0] = ' ';
	while (index < size)
	{
		temp = *((char *)addr + index++);
		temp_c[1] = get_hex(temp / 16 % 16);
		temp_c[2] = get_hex(temp % 16);
		temp = *((char *)addr + index++);
		temp_c[3] = get_hex(temp / 16 % 16);
		temp_c[4] = get_hex(temp % 16);
		write(1, &temp_c, 5);
	}
	index = 0;
	while (index < space_size)
	{
		write(1, " ", 1);
		index++;
	}
	change_non_printable_and_print(addr, size);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int temp;
	int index;
	
	index = 0;
	temp = (int)size / 16;
	while (index < temp)
	{
		print_address(addr + (16 * index), 16);
		print_contents(addr + (16 * index), 16, 1);
		index++;
	}
	temp = 70 % 16;
	print_address(addr + size - temp, temp);
	print_contents(addr + size - temp, temp, 5);
	return (addr);
}

void main()
{
	char str[70];
	char a = '!';
	for(int i = 0; i < 70; i++)
	{
		str[i] = a++;
	}
	
	ft_print_memory((void *)str, 70);



	char str2[] = "Bonjour les aminches...c est fou.tout.ce qu on peut faire avec...print_memory....lol.lol. .";
	ft_print_memory((void *)str2, 92);
}
