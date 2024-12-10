import { Module } from '@nestjs/common';
import { TypeOrmModule } from '@nestjs/typeorm';
import { ThrottlerModule, ThrottlerGuard } from '@nestjs/throttler';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { UserModule } from './Models/user/user.module';
import * as dotenv from 'dotenv';
import { User } from './Models/user/entities/user.entity';
import { AuthModule } from './Auth/auth.module';
import { Transaction } from './Models/transactions/entities/transaction.entity';
import { APP_GUARD } from '@nestjs/core';
import { GoalModule } from './Models/goal/goal.module';
import { Goal } from './Models/goal/entities/goal.entity';
import { StrategyModule } from './strategy/strategy.module';
import { Strategy } from './strategy/entities/strategy.entity';

dotenv.config();

@Module({
  imports: [
    TypeOrmModule.forRoot({
      type: 'postgres',
      host: process.env.DB_HOST,
      port: parseInt(process.env.DB_PORT),
      username: process.env.DB_USERNAME,
      password: process.env.DB_PASSWORD,
      database: process.env.DB_NAME,
      entities: [User, Transaction, Goal, Strategy],
      synchronize: true,
      logging: true,
    }),
    ThrottlerModule.forRoot([{
      ttl: 60000,
      limit: 10,
    }]),
    UserModule,
    AuthModule,
    GoalModule,
    StrategyModule,
  ],
  controllers: [AppController],
  providers: [
    AppService,
    {
      provide: APP_GUARD,
      useClass: ThrottlerGuard
    }
  ],
})
export class AppModule {}