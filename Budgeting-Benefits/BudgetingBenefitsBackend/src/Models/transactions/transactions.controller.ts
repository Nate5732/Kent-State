import { Controller, Get, Post, Body, Patch, Param, Delete, UseGuards } from '@nestjs/common';
import { TransactionsService } from './transactions.service';
import { CreateTransactionDto } from './dto/create-transaction.dto';
import { UpdateTransactionDto } from './dto/update-transaction.dto';
import { AuthGuard } from '@nestjs/passport';

@Controller('transactions')
export class TransactionsController {
  constructor(private readonly transactionsService: TransactionsService) {}

  @UseGuards(AuthGuard('jwt'))
  @Post()
  create(@Body() createTransactionDto: CreateTransactionDto) {
    console.log('\n\n\nReceived request payload:', createTransactionDto);
    return this.transactionsService.create(createTransactionDto);
  }

  @UseGuards(AuthGuard('jwt'))
  @Get()
  findAll() {
    console.log("CALLED");
  }

  @UseGuards(AuthGuard('jwt'))
  @Get(':identifier')
  async findOne(@Param('identifier') identifier: any) {
    if (!isNaN(identifier)) {
      let transaction = await this.transactionsService.findOne(Number(identifier));
      return {
        id: transaction.id,
        category: transaction.category,
        date: transaction.date,
        amount: transaction.amount
      };
    } else {
      throw new Error('Invalid identifier');
    }
  }

  @UseGuards(AuthGuard('jwt'))
  @Patch(':id')
  update(@Param('id') id: string, @Body() updateTransactionDto: UpdateTransactionDto) {
    return this.transactionsService.update(+id, updateTransactionDto);
  }

  @UseGuards(AuthGuard('jwt'))
  @Delete(':id')
  remove(@Param('id') id: string) {
    return this.transactionsService.remove(+id);
  }
}